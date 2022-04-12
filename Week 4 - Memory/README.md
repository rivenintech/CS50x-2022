# [Week 4](https://cs50.harvard.edu/x/2022/weeks/4/)

## [Lab 4](https://cs50.harvard.edu/x/2022/labs/4/)

### [Volume](https://cs50.harvard.edu/x/2022/labs/4/)

Complete the implementation of `volume.c`, such that it changes the volume of a sound file by a given factor.

- The program accepts three command-line arguments: `input` represents the name of the original audio file, `output` represents the name of the new audio file that should be generated, and `factor` is the amount by which the volume of the original audio file should be scaled.
    - For example, if `factor` is `2.0`, then your program should double the volume of the audio file in `input` and save the newly generated audio file in `output`.
- Your program should first read the header from the input file and write the header to the output file. Recall that this header is always exactly 44 bytes long.
    - Note that `volume.c` already defines a variable for you called `HEADER_SIZE`, equal to the number of bytes in the header.
- Your program should then read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time. Your program should multiply each sample by the `factor` and write the new sample to the output file.
    - You may assume that the WAV file will use 16-bit signed values as samples. In practice, WAV files can have varying numbers of bits per sample, but we’ll assume 16-bit samples for this lab.
- Your program, if it uses `malloc`, must not leak any memory.

----
<br>

## [Problem Set 4](https://cs50.harvard.edu/x/2022/psets/4/)

### [Filter-less](https://cs50.harvard.edu/x/2022/psets/4/filter/less/)

Implement the functions in `helpers.c` such that a user can apply grayscale, sepia, reflection, or blur filters to their images.

- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
- The function `sepia` should take an image and turn it into a sepia version of the same image.
- The `reflect` function should take an image and reflect it horizontally.
- Finally, the `blur` function should take an image and turn it into a box-blurred version of the same image.

----

### [Filter-more](https://cs50.harvard.edu/x/2022/psets/4/filter/more/)

Implement the functions in `helpers.c` such that a user can apply grayscale, reflection, blur, or edge detection filters to their images.

- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
- The `reflect` function should take an image and reflect it horizontally.
- The `blur` function should take an image and turn it into a box-blurred version of the same image.
- The `edges` function should take an image and highlight the edges between objects, according to the Sobel operator.

----

### [Recover](https://cs50.harvard.edu/x/2022/psets/4/recover/)

Implement a program called `recover` that recovers JPEGs from a forensic image.

- Implement your program in a file called `recover.c` in a directory called `recover`.
- Your program should accept exactly one command-line argument, the name of a forensic image from which to recover JPEGs.
- If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and `main` should return `1`.
- If the forensic image cannot be opened for reading, your program should inform the user as much, and `main` should return `1`.
- The files you generate should each be named `###.jpg`, where `###` is a three-digit decimal number, starting with `000` for the first image and counting up.
- Your program, if it uses `malloc`, must not leak any memory.


[*Source*](https://cs50.harvard.edu/x/2022/weeks/4/)