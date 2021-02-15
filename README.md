# BrandOS

BrandOS is a a lightweight x86 legacy bios operating system using [GRUB](https://www.gnu.org/software/grub/).

## Building

### Requirements:
* qemu-system
* i386/i686 [cross compiler](https://github.com/TheRealJoe24/osdev-i386-cross-utils)
* gnu grub version 2.05 (other versions may also work)

### Build Scripts:

```sh
./build.sh
```
```sh
./iso.sh # builds from source and creates iso with grub
```
```sh
./qemu-run.sh # makes iso and runs with qemu
```
```sh
./clean.sh
```

## Structure
The code structure is based lightly on the osdev wiki meaty skeleton.

## Contributing
Pull requests are welcome, however I am currently not accepting any major changes.

## Roadmap
* ~~Setup project structure~~
* Implmement basic kernel lib
* Implement IDT/GDT in the kernel
* Implement timer and keyboard IRQs
* Enter userland
  * Implememnt libc

## License
[LICENSE](LICENSE) [(GPL 3)](https://choosealicense.com/licenses/gpl-3.0/)