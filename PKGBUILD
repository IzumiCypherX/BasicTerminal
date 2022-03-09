pkgname="Basic-Terminal"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="A Basic Linux Terminal Emulator Base"
arch=("x86_64")
license=("GPL")
source=("term.c")
sha512sums=("SKIP")

package(){
    echo "gcc -O2 -Wall $(pkg-config --cflags vte-2.91) term.c -o term $(pkg-config --libs vte-2.91) && ./term" > "${srcdir}/basic-terminal.sh"
    mkdir -p "${pkgdir}/usr/bin"
    cp "${srcdir}/basic-terminal.sh" "${pkgdir}/usr/bin/basic-terminal"
    chmod +x "${pkgdir}/usr/bin/basic-terminal"
}