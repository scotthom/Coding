mkdir ~/Desktop/copy_music
find ~/Music/iTunes/iTunes\ Media/Music -iname "*.mp3" -exec cp {} ~/Desktop/copy_music \;
find ~/Music/iTunes/iTunes\ Media/Music -iname "*.wav" -exec cp {} ~/Desktop/copy_music \;
