# osbr

### Open Source Bible Reader

As the name of the app says it: osbr is an open source Bible reader...

Written in C++17 it's a simple console application to read the Bible (for the moment only in french) from text files located in a folder of the app.

I plane to put several different translations of the Bible that are Royalty-free. At the moment when I write this README file, the only translation available is the "Bible à la Colombe", a french translation of the Bible based on the Louis Segond translation.

The others Royalty-free translations that will be added are the following (all in french, for the moment):

* Darby
* Segond

I'd like also to add the original hebrew and greek texts.

If you'd like to contribute to this project, I'll be more than happy! It's not particularly a difficult one, but for me who is a beginner in C++, it's challenging, even if it's just a console app.

I'll update this file, God willing, to add more infos about the project and the state of its development.

---

To use the program you'll need the folder containing the text files of the Bible, and put it at the root of the project. The [archive](https://stephane.life/projects/osbr/BibleDir.zip) of this folder is located on this page:

 [https://stephane.life/projects/osbr/](https://stephane.life/projects/osbr/)

Compile without problem, with g++ 8, under Fedora 28:
```bash
g++ -std=c++17 -o bible main.cpp biblefiles.cpp biblib.cpp -lstdc++fs
```

That's all for the moment...