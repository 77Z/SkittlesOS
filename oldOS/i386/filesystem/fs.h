#ifndef _FS_H_
#define _FS_H_

int initFS(int bootdrive);
int write_file(char *file_location, char* data);

#endif /* _FS_H_ */