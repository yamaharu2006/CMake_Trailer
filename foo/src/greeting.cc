#include "greeting.h"
#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif
	extern int get_time();
#ifdef __cplusplus
}
#endif

int greet()
{
	switch (get_time())
	{
	case 0:
	case 1:
	case 2:
	case 3:
		std::cout << "Good Night" << std::endl;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		std::cout << "Good Morning" << std::endl;
		break;
	case 11:
	case 12:
	case 13:
	case 14:
		std::cout << "Hello" << std::endl;
		break;
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
		std::cout << "Good Night" << std::endl;
		break;
	default:
		std::cout << "Time is Broken" << std::endl;
		break;
	}
	return 0;
}
