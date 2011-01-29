//http://www.gamedev.net/reference/articles/article2091.asp

short (*BigShort) ( short s );
short (*LittleShort) ( short s );
int (*BigLong) ( int i );
int (*LittleLong) ( int i );
float (*BigFloat) ( float f );
float (*LittleFloat) ( float f );

short ShortSwap( short s )
{
  unsigned char b1, b2;

  b1 = s & 255;
  b2 = (s >> 8) & 255;

  return (b1 << 8) + b2;
}

short ShortNoSwap( short s )
{
  return s;
}


int LongSwap (int i)
{
  unsigned char b1, b2, b3, b4;

  b1 = i & 255;
  b2 = ( i >> 8 ) & 255;
  b3 = ( i>>16 ) & 255;
  b4 = ( i>>24 ) & 255;

  return ((int)b1 << 24) + ((int)b2 << 16) + ((int)b3 << 8) + b4;
}

int LongNoSwap( int i )
{
  return i;
}


float FloatSwap( float f )
{
  union
  {
    float f;
    unsigned char b[4];
  } dat1, dat2;

  dat1.f = f;
  dat2.b[0] = dat1.b[3];
  dat2.b[1] = dat1.b[2];
  dat2.b[2] = dat1.b[1];
  dat2.b[3] = dat1.b[0];
  return dat2.f;
}

float FloatNoSwap( float f )
{
  return f;
}

bool BigEndianSystem;  //you might want to extern this

void InitEndian( void )
{
  char SwapTest[2] = { 1, 0 };

  if( *(short *) SwapTest == 1 )
  {
    //little endian
    BigEndianSystem = false;

    //set func pointers to correct funcs
    BigShort = ShortSwap;
    LittleShort = ShortNoSwap;
    BigLong = LongSwap;
    LittleLong = LongNoSwap;
    BigFloat = FloatSwap;
    LittleFloat = FloatNoSwap;
  }
  else
  {
    //big endian
    BigEndianSystem = true;

    BigShort = ShortNoSwap;
    LittleShort = ShortSwap;
    BigLong = LongNoSwap;
    LittleLong = LongSwap;
    BigFloat = FloatSwap;
    LittleFloat = FloatNoSwap;
  }
}
