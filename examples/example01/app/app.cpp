// +---------------------------------------------------------------------------
// |
// |   Botan GPL Source Code
// |   Copyright (c) 2021 XNerv Ltda (http://xnerv.com). All rights reserved.
// |
// |   This file is part of the Botan GPL Source Code.
// |
// |   Botan Source Code is free software: you can redistribute it and/or
// |   modify it under the terms of the GNU General Public License
// |   as published by the Free Software Foundation, either version 3
// |   of the License, or (at your option) any later version.
// |
// |   Botan Source Code is distributed in the hope that it will be useful,
// |   but WITHOUT ANY WARRANTY; without even the implied warranty of
// |   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |   GNU General Public License for more details.
// |
// |   You should have received a copy of the GNU General Public License
// |   along with Botan Source Code. If not, see <http://www.gnu.org/licenses/>.
// |
// +---------------------------------------------------------------------------

#include <botan/botan.h>
#include <iostream>

int main()
{
    const std::string chosen_aead_mode = "ChaCha20Poly1305";

    // a key from somewhere
    auto key = Botan::system_rng().random_vec(32);

    // data from somewhere ...
    const uint8_t                 ptext[32] = {0};
    const size_t                  ptext_len = sizeof(ptext);
    Botan::secure_vector<uint8_t> buf(ptext, ptext + ptext_len);

    // create the aead object
    std::unique_ptr<Botan::AEAD_Mode> aead = Botan::AEAD_Mode::create_or_throw(chosen_aead_mode,
                                                                               Botan::ENCRYPTION);

    // set key
    aead->set_key(key);

    // chose a random nonce of whatever length aead wants
    auto nonce = Botan::system_rng().random_vec(aead->default_nonce_length());

    // begin processing using nonce
    aead->start(nonce);

    // process the entire message in buf in one go, appending tag
    aead->finish(buf);

    // output nonce and ciphertext
    std::cout << Botan::hex_encode(nonce) << Botan::hex_encode(buf) << "\n";
}
