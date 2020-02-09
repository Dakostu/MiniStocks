**ATTENTION: THIS PROGRAM IS IN THE PROCESS OF SWITCHING APIs FOR FINANCIAL INFORMATION. DATA FROM stooq.com IS BEING USED NOW.** 

# MiniStocks

![preview image](https://i.imgur.com/8aCoIzE.png)

MiniStocks is a Qt widget focussing on a minimalistic display of real-time stock dataa .

As of now, MiniStocks is in version of 0.2 which means "barely functional". It is still quite rough around the edges but basic functionality is established.

# How to install MiniStocks

MiniStocks is a QMake project that can be opened with Qt Creator, but it can be also compiled via the following Terminal commands:

1. `qmake StockTicker.pro` (optional if the supplied Makefile doesn't work)
2. `sudo make install`

These commands will install MiniStocks in your /usr/local/bin directory.

# How to use MiniStocks

The application is called MiniStocks in the start menu and "ministocks" in the CLI.

MiniStocks fetches real-time stock data from Yahoo Finance to update its stock ticker. The list of ticker symbols is saved in a savefile, located in the "./ministocks" folder in your home directory. 

To add and/or delete ticker symbols while the program is running, open the Settings window by right-clicking on the MainWindow and selecting "Settings" or using the designated shortcut.

## Shortcuts (MainWindow)
- S: Open Settings window
- A: Open "About" window
- +: Increase font size
- -: Decrease font size
- Ctrl+Q: Close program

## Shortcuts (Settings window)
- +: Add ticker
- -: Remove selected ticker 
- Ctrl+S: Save 

# ToDo
- improve memory management 
- improve stock ticker update implementation
- fix window size update when decreasing font sizes or deleting a ticker
- add more settings 
