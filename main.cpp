#include "Includes.h"
#include "Controladora.h"

int main()
{
    Controladora* c = new Controladora();
    c->control0();
    delete c;

    return 0;
}