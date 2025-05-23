{
  description = "dmenu";

  inputs.nixpkgs.url = "nixpkgs/nixpkgs-unstable";

  outputs =
    { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
      configFile = import ./config.nix {
        inherit pkgs;
      };
    in
    {
      defaultPackage.x86_64-linux =
        with import nixpkgs { system = "x86_64-linux"; };
        stdenv.mkDerivation {
          name = "dmenu";
          version = "5.3";

          src = self;

          nativeBuildInputs = with pkgs; [ pkg-config ];
          buildInputs = with pkgs; [
            fontconfig
            xorg.libX11
            xorg.libXinerama
            zlib
            xorg.libXft
          ];

          preConfigure = ''
            makeFlagsArray+=(
              PREFIX="$out"
              CC="$CC"
              # default config.mk hardcodes dependent libraries and include paths
              INCS="`$PKG_CONFIG --cflags fontconfig x11 xft xinerama`"
              LIBS="`$PKG_CONFIG --libs   fontconfig x11 xft xinerama`"
            )
          '';

          prePatch = ''
            cp ${configFile} config.def.h
          '';

          postPatch = ''
            sed -ri -e 's!\<(dmenu|dmenu_path|stest)\>!'"$out/bin"'/&!g' dmenu_run
            sed -ri -e 's!\<stest\>!'"$out/bin"'/&!g' dmenu_path
          '';

          meta = {
            mainProgram = "dmenu";
          };
        };
    };
}
