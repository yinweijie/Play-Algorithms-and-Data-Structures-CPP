#ifndef __UF_H__
#define __UF_H__

class UF
{
public:
    virtual int getSize() = 0;
    virtual bool isConnected(int p, int q) = 0;
    virtual void unionElement(int p, int q) = 0;
};

#endif