#ifndef ENS_H
#define ENS_H

#include <GL/gl.h>
#include <GL/glu.h>

class Ennemy {
public:
        Ennemy() { };
        Ennemy(int a, int b, int c);
        int x, y, z;
        GLuint texture;
        int area () {return (x*y);}
        void set_values (int a, int b, int c);
};

/*
class Ennemy
{
private:
    int m_nMonth;
    int m_nDay;
    int m_nYear;

    Ennemy() { } // private default constructor

public:
    Ennemy(int nMonth, int nDay, int nYear);

    void SetDate(int nMonth, int nDay, int nYear);

    int GetMonth() { return m_nMonth; }
    int GetDay()  { return m_nDay; }
    int GetYear() { return m_nYear; }
};*/

#endif // ENS_H
