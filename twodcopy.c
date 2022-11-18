#include <linux/kernel.h>
#include <linux/syscalls.h>


SYSCALL_DEFINE4(kernel_2d_memcpy, float**, src, float**, dest, int, len1, int, len2);
{
    float buffer; 

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if (__copy_from_user(buffer, src[i][j], sizeof(float)))
                return -EFAULT;

            if (__copy_to_user(dest[i][j], buffer, sizeof(float)))
                return -EFAULT;
        }
    }

    return 0;
}
