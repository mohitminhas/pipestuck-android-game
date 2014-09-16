//
CG Project April 18, 2014

Aseem Gupta
Mohit Minhas
Tharun Kumar reddy

//
******************************************************************************
PipeStuck.apk has the final deployed package.

Please visit the youtube link http://youtu.be/hNPnkqJVWVA to see the app working.

******************************************************************************
-------------------------------------------------------------------------------------



#If you have an Android device, connect it to the computer.

NOTE: 
1. To run the file, you must have adb (Android SDK) downloaded. To download the SDK starter package(not complete bundle, just Android SDKs) from http://developer.android.com/sdk/index.html.
2. Install all the packages.
3. After the download is completed, unzip it to any folder. Locate adb under platform tools.
4. To recognize adb as command in cmd, you must set adb's path in environment variables.
5. Press Windows Key, and type environment variables, select Edit Environment variables.
6. Locate Path as variable name in the System variables, and then add the path of adb in that after putting semicolon after the existing entries.

Now, we have adb on our computer 

Follow the steps below:
a. Go to bin directory in the folder proj.android
b.Locate PipeStuck.apk
c. Open cmd, and go to the directory containing PipeStuck.apk
d. run the following command ---> adb install -r PipeStuck.apk

Now, it will take a few minutes to install the app on Android phone.
Go to Apps on your mobile and see PipeStuck. Open it and you're good to go.
-------------------------------------------------------------------------------------


#If you don't have an Android phone.

******************************************************************************
1. See the app working on youtube link: http://youtu.be/hNPnkqJVWVA

******************************************************************************
2. Or, you may download the complete Android Bundle from http://developer.android.com/sdk/index.html which will include eclipse, and Android SDK along with adb.
a. Unzip the package and open eclipse.
b. See Window in toolbar and locate the path Window->SDK manager.
c. Install at least API 15 and API 8.
d. After that go to Window->Android virtual device(AVD) and configure the AVD as Android 2.2 or Android 4.0.3 and run the virtual machine. It will act as your android phone plugged in. You may now follow the same steps as having an Android device.

******************************************************************************
3. Alternatively, you could use an Android phone emulator such as BlueStacks or Windroy, and install the apk in that.
------------------------------------------------------------------------------------
