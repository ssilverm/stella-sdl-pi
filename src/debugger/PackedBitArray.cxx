//============================================================================
//
//   SSSS    tt          lll  lll       
//  SS  SS   tt           ll   ll        
//  SS     tttttt  eeee   ll   ll   aaaa 
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2014 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
// $Id: PackedBitArray.cxx 3021 2014-10-26 19:51:02Z stephena $
//============================================================================

#include "bspf.hxx"
#include "PackedBitArray.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
PackedBitArray::PackedBitArray(uInt32 length)
  : words(length / WORD_SIZE + 1)
{
  bits = new uInt32[ words ];

  for(uInt32 i = 0; i < words; ++i)
    bits[i] = 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
PackedBitArray::~PackedBitArray()
{
  delete[] bits;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
uInt32 PackedBitArray::isSet(uInt32 bit) const
{
  uInt32 word = bit / WORD_SIZE;
  bit %= WORD_SIZE;

  return (bits[word] & (1 << bit));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
uInt32 PackedBitArray::isClear(uInt32 bit) const
{
  uInt32 word = bit / WORD_SIZE;
  bit %= WORD_SIZE;

  return !(bits[word] & (1 << bit));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void PackedBitArray::toggle(uInt32 bit)
{
  uInt32 word = bit / WORD_SIZE;
  bit %= WORD_SIZE;

  bits[word] ^= (1 << bit);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void PackedBitArray::set(uInt32 bit)
{
  uInt32 word = bit / WORD_SIZE;
  bit %= WORD_SIZE;

  bits[word] |= (1 << bit);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void PackedBitArray::clear(uInt32 bit)
{
  uInt32 word = bit / WORD_SIZE;
  bit %= WORD_SIZE;

  bits[word] &= (~(1 << bit));
}
