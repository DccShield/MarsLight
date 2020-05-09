#ifndef MarsLight_h
#define MarsLight_h

enum{
  TripleFlash = 0,
  RandomFour,
};

class MarsLight
{
public:
  MarsLight(unsigned char ch,unsigned char mode);
  void stateCheck();
  
private:
  char state = ST_INIT;
  unsigned char port;
  unsigned char mode;
  unsigned long Previous;
  int LuminousAddres;
  char LuminousPattern[50];
  int cnt;
  
  enum{
    ST_INIT = 0,
    ST_RUN,
    ST_STOP,
    ST_NEXT,
  };
  
};

#endif
