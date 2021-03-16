void dummy_function() {}

void main() {
	char* video_memory = (char*) 0xb8000;
	*video_memory = 'X';

	// We don't have to return a status code, hence why this is a void
	// We don't use C standard libraries remember? WE DO WHAT WE WANT
}
