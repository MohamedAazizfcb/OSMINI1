#include "TIME.h"

TIME* TIME::instance = NULL;
TIME::TIME(void)
{
	time = 0;
}

TIME* TIME::getInstance()
{
    if (instance == NULL)
    {
        instance = new TIME();
    }

    return instance;
}

TIME::~TIME(void)
{
}
