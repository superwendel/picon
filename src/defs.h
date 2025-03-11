#define TARGET_FPS 60
#define FRAME_TIME_MS (1000 / TARGET_FPS)

#define MAX_SND_CHANNELS 16

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 180
#define PERSISTENT_ARENA_SIZE 1024 * 1024 // 1 MB


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef int b32;
typedef _Bool b8;

#define true 1
#define false 0

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "u8 should= 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "u16 should= 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "u32 should= 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "u64 should= 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "i8 should= 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "i16 should= 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "i32 should= 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "i64 should= 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "f32 should= 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "f64 should= 8 bytes");

// Inline
#ifdef _MSC_VER
#define PINLINE __forceinline
#define PNOINLINE __declspec(noinline)
#else
#define PINLINE static inline
#define PNOINLINE
#endif

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define STRCPY(dest, src)             \
strncpy(dest, src, sizeof(dest)); \
dest[sizeof(dest) - 1] = '\0'
#define STRNCPY(dest, src, n) \
strncpy(dest, src, n);    \
	dest[n - 1] = '\0'
