#include "Math.h"

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return (int) x + y;
}

int Math::Add(double x, double y, double z)
{
	return (int) x + y + z;
}

int Math::Mul(int x, int y)
{
	return x*y;
}

int Math::Mul(int x, int y, int z)
{
	return x*y*z;
}

int Math::Mul(double x, double y)
{
	return (int) x*y;
}

int Math::Mul(double x, double y, double z)
{
	return (int) x*y*z;
}

int Math::Add(int count, ...)
{
	int result = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}

char* Math::Add(const char* str1, const char* str2)
{
	int s1, s2, s3, i = 0;
	char *a;

	s1 = strlen(str1);
	s2 = strlen(str2);
	s3 = s1 + s2 + 1;
	//a = malloc((size_t)s3);
	a = (char*) malloc(strlen(str1) + strlen(str2) + 1);
	

	if (str1 == nullptr || str2 == nullptr) {

		return nullptr;
	}
	else {
		while (*str1 != '\0') {
			a[i] = *str1;
			str1++;
			i++;
		}
		while (*str2 != '\0') {
			a[i] = *str2;
			str2++;
			i++;
		}

		a[i] ='\0';

		return a;
	}
}



