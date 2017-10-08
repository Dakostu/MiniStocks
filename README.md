# MiniStocks

![preview image](https://i.imgur.com/8aCoIzE.png)

MiniStocks is a Qt widget focussing on a minimalistic display of real-time stock data.

As of now, MiniStocks is in version of 0.1 which means "barely functional". It is still quite rough around the edges but basic functionality is established.

Install MiniStocks by downloading and opening the "build" folder and typing "make" in a CLI. The application is called MiniStocks.

# How to use MiniStocks

MiniStocks fetches real-time stock data from Yahoo Finance to update its stock ticker. The list of ticker symbols is saved in a savefile, located in the "./ministocks" folder in your home directory. 

To add and/or delete ticker symbols while the program is running, open the Settings window by right-clicking on the MainWindow and selecting "Settings" or using the designated shortcut.

## Shortcuts (MainWindow)
- S: Open Settings window
- A: Open "About" window
- +: Increase font size
- -: Decrease font size.
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
