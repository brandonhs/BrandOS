# BrandOS

BrandOS is a a lightweight x86 legacy bios operating system using [GRUB](https://www.gnu.org/software/grub/).

## Building

### Requirements:
* qemu-system
* i386/i686 [cross compiler](https://github.com/TheRealJoe24/osdev-i386-cross-utils)
* gnu grub version 2.05 (other versions may also work)

### Commands:

To build and generate iso image:
```sh
make
```
To clean directory:
```sh
make clean
```
To run with qemu emulator:
```sh
make run
```

## Structure
TODO

## Contributing
Pull requests are welcome, however I am currently not accepting any major changes.

## Roadmap
* ~~Setup project structure~~
* ~~Implmement basic kernel lib~~
* Implement IDT/GDT in the kernel
  * ~~GDT~~
  * IDT
* Implement timer and keyboard IRQs
* Implement memory [managment](https://wiki.osdev.org/Memory_management)
  * x86: segmentation
  * paging
  * Virtual memory
* Enter userland
  * Implememnt libc

## End Goal
Create a self-hosting OS (Make an OS which can build itself)

## Why am I trying to write an OS not even meant for modern hardware?
I have seen a lot of people on forums of all places who say that *"the purpose of developing an operating system is to make a killer OS with all kinds of applications in the real world"*. I don't agree with that. Instead, I am writing an operating system for the sole purpose of experience and fun. To be able to say, *"I made an operating system in high school"*, is my dream for this whole endeavor. To say that I am new to operating system development, is an understatment, however **the experience of learning is also quite important to me**.

The experience which comes out of low level os development has all kinds of real world applications. Complex build systems, memory manangment and allocation, and an understanding of kernel development are just a few which come to mind.

To actually answer the question, I have developed the build system with the mindset that I may add support for more modern systems in the future but for now, I am just enjoying the experience of writing an OS from the ground up.

## License
[LICENSE](LICENSE) [(GPL 3)](https://choosealicense.com/licenses/gpl-3.0/)