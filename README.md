# Creepers

Creepers is a OpenFrameworks game, based on MOBA genre.


## How to play

Defeat the enemies with your gun and try to make more points! Don't let them touch you because you die.

#### Commands

|Key                |Function                           |
|:-----------------:|-----------------------------------|
|Left Button        |Shoot         
|Right Button       |Move player
|Middle Button      |Block waypoint if they are visible
|ctrl + left button |Add Waypoint in the map
|i                  |Show Waypoints
|+                  |Adds enemy speed
|-                  |Subtracts enemy speed
|a                  |Adds enemy spawn time
|s                  |Subtracts enemy spawn time
|esc                |Pause


## Features

|Feature                |File                               |
|:---------------------:|-----------------------------------|
|Map                    |Map.h                              |
|Waypoints              |WaypointManager.h and Waypoint.h   |
|Register Waypoint      |Line 163 - offApp.cpp              |
|Block Waypoint         |Line 159 - offApp.cpp              |
|Show Waypoints         |Line 89 - offApp.cpp               |
|Enemy                  |EnemyManager.h and Enemy.h         |
|Change enemy speed     |Line 93 and 96 - offApp.cpp        |
|Player                 |Player.h                           |
|Enemy follows player   |Line 114 Enemy.h                   |
|Player shoot           |Line 66 - offApp.cpp               |


## Screenshots

![Game](http://i.imgur.com/veDtuCa.png)
![GameOver](http://i.imgur.com/1cZPqIC.png)




      



