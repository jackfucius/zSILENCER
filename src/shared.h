#ifndef SHARED_H
#define SHARED_H

#ifdef __APPLE__
#define POSIX
#endif
#ifdef __linux
#define POSIX
#endif

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_syswm.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef POSIX
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <poll.h>
#include <fcntl.h>
#include <pwd.h>
typedef int SOCKET;
#define closesocket close
#elif _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#undef INTERFACE
#ifndef EADDRINUSE
#define EADDRINUSE WSAEADDRINUSE
#endif
#ifndef ECONNRESET
#define ECONNRESET WSAECONNRESET
#endif
#ifndef ECONNREFUSED
#define ECONNREFUSED WSAECONNREFUSED
#endif
#define SHUT_RDWR SD_BOTH
#ifndef errno
#define errno WSAGetLastError()
#endif
typedef int socklen_t;
#define ioctl ioctlsocket
#define snprintf _snprintf
#endif
#ifdef __ANDROID__
#include <android/log.h>
#include <jni.h>
#include <SDL_opengles2.h>
#define printf(...) __android_log_print(ANDROID_LOG_DEBUG, "TAG", __VA_ARGS__);
extern JNIEnv * jenv;
extern JavaVM * jvm;
#else
#include <SDL_opengl.h>
#endif
void CDResDir(void);
void CDDataDir(void);

#endif