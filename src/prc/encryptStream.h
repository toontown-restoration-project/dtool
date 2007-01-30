// Filename: encryptStream.h
// Created by:  drose (01Sep04)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef ENCRYPTSTREAM_H
#define ENCRYPTSTREAM_H

#include "dtoolbase.h"

// This module is not compiled if OpenSSL is not available.
#ifdef HAVE_OPENSSL

#include "encryptStreamBuf.h"

////////////////////////////////////////////////////////////////////
//       Class : IDecryptStream
// Description : An input stream object that uses OpenSSL to decrypt
//               the input from another source stream on-the-fly.
//
//               Attach an IDecryptStream to an existing istream that
//               provides encrypted data, as generated by an
//               OEncryptStream, and read the corresponding
//               unencrypted data from the IDecryptStream.
//
//               Seeking is not supported.
////////////////////////////////////////////////////////////////////
class EXPCL_DTOOLCONFIG IDecryptStream : public istream {
public:
  INLINE IDecryptStream();
  INLINE IDecryptStream(istream *source, bool owns_source,
                        const string &password);

  INLINE IDecryptStream &open(istream *source, bool owns_source,
                              const string &password);
  INLINE IDecryptStream &close();

  INLINE const string &get_algorithm() const;
  INLINE int get_key_length() const;
  INLINE int get_iteration_count() const;

private:
  EncryptStreamBuf _buf;
};

////////////////////////////////////////////////////////////////////
//       Class : OEncryptStream
// Description : An input stream object that uses OpenSSL to encrypt
//               data to another destination stream on-the-fly.
//
//               Attach an OEncryptStream to an existing ostream that
//               will accept encrypted data, and write your
//               unencrypted source data to the OEncryptStream.
//
//               Seeking is not supported.
////////////////////////////////////////////////////////////////////
class EXPCL_DTOOLCONFIG OEncryptStream : public ostream {
public:
  INLINE OEncryptStream();
  INLINE OEncryptStream(ostream *dest, bool owns_dest, 
                        const string &password);

  INLINE OEncryptStream &open(ostream *dest, bool owns_dest, 
                              const string &password);
  INLINE OEncryptStream &close();

  INLINE void set_algorithm(const string &algorithm);
  INLINE void set_key_length(int key_length);
  INLINE void set_iteration_count(int iteration_count);

private:
  EncryptStreamBuf _buf;
};

#include "encryptStream.I"

#endif  // HAVE_OPENSSL


#endif


