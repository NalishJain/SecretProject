#include <linux/kernel.h>
#include <linux/syscalls.h>


SYSCALL_DEFINE4(kernel_2d_memcpy, float**, src, float**, dest, int, len1, int, len2)
{
    float buffer[len2];
    for(int i3 = 0; i3 < len1; i3++){
        if (__copy_from_user(buffer, src[i3], sizeof(float)*(len2)))
            return -EFAULT;

        if (__copy_to_user(dest[i3], buffer, sizeof(float)*(len2)))
            return -EFAULT;
 
    }

    return 0;
}
