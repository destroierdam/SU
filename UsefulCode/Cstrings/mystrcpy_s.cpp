template<size_t destSize, size_t srcSize>
size_t mystrcpy_s(char (&dest)[destSize], const char (&src)[srcSize])
{
	size_t i;
	for (i = 0; i < min(destSize,srcSize) && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	if (i <= sizeof(dest) - 1) //Check if there is a place to put '\0'
	{
		dest[i] = '\0';
	}
	else
	{
		cerr << "destination char[] too small" << endl;
		
		// Put '\0' at the end of dest
		dest[sizeof(dest) - 1] = '\0';

		throw std::exception("destination char[] too small");
	}

	return i; // return the number of elements copied
}
