/*  =========================================================================
    libcert_public_key - PublicKey class header

    Copyright (C) 2019 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef LIBCERT_PUBLIC_KEY_H_INCLUDED
#define LIBCERT_PUBLIC_KEY_H_INCLUDED

#include <string>
#include <openssl/evp.h>

#include "libcert_pem_exportable.h"

namespace fty
{
    class CertificateX509;
    class Csr509;
    class Keys;

    class PublicKey : public PemExportable
    {
    public:
        ~PublicKey();

        std::string getPem() const override;
    private:
        PublicKey(EVP_PKEY * key);
        EVP_PKEY * m_evpPkey = NULL;

    friend class CertificateX509;
    friend class CsrX509;
    friend class Keys;
    };
}

//  Self test of this class
void libcert_public_key_test (bool verbose);

#endif
