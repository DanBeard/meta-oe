SUMMARY = "OpenFlow communications protocol"
DESCRIPTION = "\
Open standard that enables researchers to run experimental protocols in \
contained networks.  OpenFlow is a communications interface between \
control and forwarding planes of a software-defined networking architecture.\
"
HOMEPAGE = "http://www.openflow.org"

SECTION = "networking"
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://COPYING;md5=e870c934e2c3d6ccf085fd7cf0a1e2e2"

SRC_URI = "git://gitosis.stanford.edu/openflow.git;protocol=git"

DEPENDS = "virtual/libc"

EXTRA_OECONF += "KARCH=${TARGET_ARCH}"

PACKAGECONFIG ??= "openssl"
PACKAGECONFIG[openssl] = "--enable-ssl,--disable-ssl, openssl, libssl"

S = "${WORKDIR}/git"

inherit autotools

do_configure() {
    ./boot.sh
    oe_runconf
}

do_install_append() {
    # Remove /var/run as it is created on startup
    rm -rf ${D}${localstatedir}/run
}
