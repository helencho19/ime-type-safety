#include <string>
#include <vector>
// Using x86-64 gcc 12.2; no fancy compiler optimizations (unless specified o/w)

// Int on the heap with new and delete
void allocAndFreeInt() {
    int *nPtr = new int(91);
    *nPtr++;
    delete nPtr;
}
// allocAndFreeInt():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     edi, 4
//         call    operator new(unsigned long)
//         mov     DWORD PTR [rax], 91
//         mov     QWORD PTR [rbp-8], rax
//         add     QWORD PTR [rbp-8], 4
//         mov     rax, QWORD PTR [rbp-8]
//         test    rax, rax
//         je      .L3
//         mov     esi, 4
//         mov     rdi, rax
//         call    operator delete(void*, unsigned long)
// .L3:
//         nop
//         leave
//         ret

// Int array on the heap with new and delete
void allocFreeIntArray() {
    int *arrPtr = new int[5];
    arrPtr[0] = 2;
    delete arrPtr;
}
// allocFreeIntArray():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     edi, 20
//         call    operator new[](unsigned long)
//         mov     QWORD PTR [rbp-8], rax
//         mov     rax, QWORD PTR [rbp-8]
//         mov     DWORD PTR [rax], 2
//         mov     rax, QWORD PTR [rbp-8]
//         test    rax, rax
//         je      .L3
//         mov     esi, 4
//         mov     rdi, rax
//         call    operator delete(void*, unsigned long)
// .L3:
//         nop
//         leave
//         ret

// Char array with new and delete
void allocFreeCharArray() {
    char *arrPtr = new char[5];
    delete arrPtr;
}
// allocFreeCharArray():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     edi, 5
//         call    operator new[](unsigned long)
//         mov     QWORD PTR [rbp-8], rax
//         mov     rax, QWORD PTR [rbp-8]
//         test    rax, rax
//         je      .L3
//         mov     esi, 1
//         mov     rdi, rax
//         call    operator delete(void*, unsigned long)
// .L3:
//         nop
//         leave
//         ret

// Int on the stack
int getInt() {
    int a = 4;
    return a;
}
// getInt():
//         push    rbp
//         mov     rbp, rsp
//         mov     DWORD PTR [rbp-4], 4
//         mov     eax, DWORD PTR [rbp-4]
//         pop     rbp
//         ret

char getChar() {
    char a = 'a';
    return a;
}
// getChar():
//         push    rbp
//         mov     rbp, rsp
//         mov     BYTE PTR [rbp-1], 97
//         movzx   eax, BYTE PTR [rbp-1]
//         pop     rbp
//         ret

// Float on the stack
float getFloat() {
    float f = 1.0;
    return f;
}
// getFloat():
//         push    rbp
//         mov     rbp, rsp
//         movss   xmm0, DWORD PTR .LC0[rip]
//         movss   DWORD PTR [rbp-4], xmm0
//         movss   xmm0, DWORD PTR [rbp-4]
//         pop     rbp
//         ret
// .LC0:
//         .long   1065353216

/////////////////// ARRAYS ///////////////////
void makeIntArrayNoFill() {
    int arr[3];
}
// makeIntArrayNoFill():
//         push    rbp
//         mov     rbp, rsp
//         nop
//         pop     rbp
//         ret

void makeIntArrayPartialFill() {
    int arr[3];
    arr[1] = 1;
}
// makeIntArrayPartialFill():
//         push    rbp
//         mov     rbp, rsp
//         mov     DWORD PTR [rbp-8], 1
//         nop
//         pop     rbp
//         ret

void makeDoubleArray() {
    double arr[2];
    arr[0] = 1.0;
    arr[1] = 2.0;
}
// makeDoubleArray():
//         push    rbp
//         mov     rbp, rsp
//         movsd   xmm0, QWORD PTR .LC0[rip]
//         movsd   QWORD PTR [rbp-16], xmm0
//         movsd   xmm0, QWORD PTR .LC1[rip]
//         movsd   QWORD PTR [rbp-8], xmm0
//         nop
//         pop     rbp
//         ret
// .LC0:
//         .long   0
//         .long   1072693248
// .LC1:
//         .long   0
//         .long   1073741824

double returnDoubleArrayVal() {
    double arr[2] = {1.0, 2.0};
    return arr[0];
}
// returnDoubleArrayVal():
//         push    rbp
//         mov     rbp, rsp
//         movsd   xmm0, QWORD PTR .LC0[rip]
//         movsd   QWORD PTR [rbp-16], xmm0
//         movsd   xmm0, QWORD PTR .LC1[rip]
//         movsd   QWORD PTR [rbp-8], xmm0
//         movsd   xmm0, QWORD PTR [rbp-16]
//         movq    rax, xmm0
//         movq    xmm0, rax
//         pop     rbp
//         ret
// .LC0:
//         .long   0
//         .long   1072693248
// .LC1:
//         .long   0
//         .long   1073741824

// Float array on the stack
void makeFloatArray() {
    float arr [2];
    arr[0] = 1.0f;
    arr[1] = 1.5f;
}
// makeFloatArray():
//         push    rbp
//         mov     rbp, rsp
//         movss   xmm0, DWORD PTR .LC0[rip]
//         movss   DWORD PTR [rbp-8], xmm0
//         movss   xmm0, DWORD PTR .LC1[rip]
//         movss   DWORD PTR [rbp-4], xmm0
//         nop
//         pop     rbp
//         ret
// .LC0:
//         .long   1065353216
// .LC1:
//         .long   1069547520

// Strings, vectors

// String on the stack
void declareString() {
    std::string s;
}
// declareString():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 32
//         lea     rax, [rbp-32]
//         mov     rdi, rax
//         call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string() [complete object constructor]
//         lea     rax, [rbp-32]
//         mov     rdi, rax
//         call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() [complete object destructor]
//         leave
//         ret

// String on the stack
void makeHelloWorldString() {
    std::string s = "hello world";
}
// -O1 optimization just returns; maybe that's too much optimization...
// .LC0:
//         .string "hello world"
// makeHelloWorldString():
//         push    rbp
//         mov     rbp, rsp
//         push    rbx
//         sub     rsp, 56
//         lea     rax, [rbp-17]
//         mov     rdi, rax
//         call    std::allocator<char>::allocator() [complete object constructor]
//         lea     rdx, [rbp-17]
//         lea     rax, [rbp-64]
//         mov     esi, OFFSET FLAT:.LC0
//         mov     rdi, rax
//         call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string<std::allocator<char> >(char const*, std::allocator<char> const&)
//         lea     rax, [rbp-17]
//         mov     rdi, rax
//         call    std::allocator<char>::~allocator() [complete object destructor]
//         lea     rax, [rbp-64]
//         mov     rdi, rax
//         call    std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string() [complete object destructor]
//         jmp     .L9
//         mov     rbx, rax
//         lea     rax, [rbp-17]
//         mov     rdi, rax
//         call    std::allocator<char>::~allocator() [complete object destructor]
//         mov     rax, rbx
//         mov     rdi, rax
//         call    _Unwind_Resume
// .L9:
//         mov     rbx, QWORD PTR [rbp-8]
//         leave
//         ret
// .LC1:
//         .string "basic_string: construction from null is not valid"

void makeVector() {
    std::vector<int> v;
}
// makeVector():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 32
//         lea     rax, [rbp-32]
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::vector() [complete object constructor]
//         lea     rax, [rbp-32]
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::~vector() [complete object destructor]
//         leave
//         ret

void addVectorElt() {
    std::vector<int> v;
    v.push_back(91);
}
// -O1 optimization
// addVectorElt():
//         sub     rsp, 8
//         mov     edi, 4
//         call    operator new(unsigned long)
//         mov     rdi, rax
//         mov     DWORD PTR [rax], 91
//         mov     esi, 4
//         call    operator delete(void*, unsigned long)
//         add     rsp, 8
//         ret

// No optimization
// addVectorElt():
//         push    rbp
//         mov     rbp, rsp
//         push    rbx
//         sub     rsp, 40
//         lea     rax, [rbp-48]
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::vector() [complete object constructor]
//         mov     DWORD PTR [rbp-20], 91
//         lea     rdx, [rbp-20]
//         lea     rax, [rbp-48]
//         mov     rsi, rdx
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::push_back(int&&)
//         lea     rax, [rbp-48]
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::~vector() [complete object destructor]
//         jmp     .L9
//         mov     rbx, rax
//         lea     rax, [rbp-48]
//         mov     rdi, rax
//         call    std::vector<int, std::allocator<int> >::~vector() [complete object destructor]
//         mov     rax, rbx
//         mov     rdi, rax
//         call    _Unwind_Resume
// .L9:
//         mov     rbx, QWORD PTR [rbp-8]
//         leave
//         ret
// .LC0:
//         .string "vector::_M_realloc_insert"

struct A {
    char c;
    int i; 
};

void mallocFreeA() {
    A* aPtr = (A*)malloc(sizeof(A));
    free(aPtr);
}
// mallocFreeA():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     edi, 8
//         call    malloc
//         mov     QWORD PTR [rbp-8], rax
//         mov     rax, QWORD PTR [rbp-8]
//         mov     rdi, rax
//         call    free
//         nop
//         leave
//         ret

// Failed malloc?

void callocFreeIntArray() {
    int* intArr = (int*) calloc(4, sizeof(int));
    free(intArr);
}
// callocFreeIntArray():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     esi, 4
//         mov     edi, 3
//         call    calloc
//         mov     QWORD PTR [rbp-8], rax
//         mov     rax, QWORD PTR [rbp-8]
//         mov     rdi, rax
//         call    free
//         nop
//         leave
//         ret

void successfulRealloc() {
    int* p = (int*) malloc(3 * sizeof(int));
    float* smallerP = (float*) realloc(p, 2 * sizeof(float));
    free(smallerP);
}
// successfulRealloc():
//         push    rbp
//         mov     rbp, rsp
//         sub     rsp, 16
//         mov     edi, 12
//         call    malloc
//         mov     QWORD PTR [rbp-8], rax
//         mov     rax, QWORD PTR [rbp-8]
//         mov     esi, 8
//         mov     rdi, rax
//         call    realloc
//         mov     QWORD PTR [rbp-16], rax
//         mov     rax, QWORD PTR [rbp-16]
//         mov     rdi, rax
//         call    free
//         nop
//         leave
//         ret
