# Info

This folder contains others folders which are the various translations of the Bible that are avalaible in the app.
Because such folders are voluminous they are uploaded on another place so that you just have to download the ones you want and then put them in the folder of the app `./data/Bible` .

The translations folders also contains folders one per book; ex:

```
data/
	Bible/
		DBY/
		LSG/
		COL/
		etc
```

Here we have the Darby translation... You can add any translation in that directory, just take a look at one of the translation available to understand how they made, for example:

```
data/
	Bible/
		DBY/
			gn/
				gn-1.txt
				gn-2.txt
				etc.
			ex/
				ex-1.txt
				ex-2.txt
				etc.
```

Each new translation will be added to the config file `biblebd.ini` automatically on startup, or you can also edit manually the `bibledb.ini` file.

You an download the Bible translations from here: [https://stephane.life/projects/osbr/](https://stephane.life/projects/osbr/)