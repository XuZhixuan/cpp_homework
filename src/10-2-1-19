#include <iostream>

char encrypt(char);
int encrypt_upper(int);
int encrypt_lower(int);

int bytes;

int main()
{
	  char love[5] = { 'L', 'o', 'v', 'e', '\0' };
	  std::cin >> bytes;

	  for (int i = 0; i < 4; i++)
	  {
		    love[i] = encrypt(love[i]);
	  }

	  std::cout << love << std::endl;

	  return 0;
}

char encrypt(char in)
{
	  in = (int)in;
	  int result;

	  if (in > 64 && in < 91)
	  {
		    result = encrypt_upper(in + bytes);
	  }
	  else if (in > 96 && in < 123)
	  {
		    result = encrypt_lower(in + bytes);
	  }

	return (char)result;
}

int encrypt_upper(int in)
{
	  if (in > 64 && in < 91)
	  {
		    return in;
	  }
	  else {
		    in -= 26;
		    return encrypt_upper(in);
	  }
}

int encrypt_lower(int in)
{
	  if (in > 96 && in < 123)
	  {
		    return in;
	  }
	  else {
		    in -= 26;
		    return encrypt_lower(in);
	  }
}
