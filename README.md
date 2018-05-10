# Filler

Custom algorithm based champion who beats other champions in a virtual arena of Filler board. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore.

The goal of this project is to introduce you to basic algorithm and to have you manipulate inputs/outputs.

- Analyse the map
- Choose the best position
- Write this position on the standard output : "Y X\n"

```
./filler_vm -f -p1 ./dwald.filler -p2 [player_2] -f [maps/your_map]
```
or use command of Makefile to see my champion in solitary game
```
make filler
```

### Start
![alt text](https://github.com/eryndi/Filler/blob/master/screenshots/START.png "Start")

### Filler game
![alt text](https://github.com/eryndi/Filler/blob/master/screenshots/GAME.png "Filler Game")

### End - Winner
![alt text](https://github.com/eryndi/Filler/blob/master/screenshots/END.png "End Winner")
