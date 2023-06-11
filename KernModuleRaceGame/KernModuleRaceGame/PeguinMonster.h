#pragma once
class PeguinMonster
{
//    //peguinMonster variablen
////overige variablen
//    int xRichtingBepaler = round(random(0, 1));
//
//    //aanpasbare variablen voor de desginer
//    // random((min waarde, max waarde))
//    float xBeginLoc = float(random(0, 900));
//    float yBeginLoc = float(random(-1800, 0));
//
//    float xCurrentPos;
//    float yCurrentPos;
//
//    int xSnelheid = xSnelheidRichtingBepaler();
//    int ySnelheid = int(random(6, 10));
//    int visuelePos = xBeginLoc + 35;
//
//
//    //transform waardes
//    float xtorso = 100.0f;
//    float ytorso = 100.0f;
//
//    // overige waardens
//    int enemysInBeeld;
//
//
//    Enemy(int _enemyID, int _enemyListSize) {
//        enemysInBeeld = _enemyListSize;
//
//        if (enemysInBeeld > 2) {
//            ySnelheid = ySnelheid - 1;
//        }
//    }
//    // laat het monster bewegen
//    void EnemyBeweger() {
//        //peguinMonster
//        penguinMonsterTekenaar(xCurrentPos, yBeginLoc);
//        xCurrentPos = nieuweLocBerekenen(xCurrentPos, ySnelheid);
//        yCurrentPos = nieuweLocBerekenen(yCurrentPos, ySnelheid);
//        xSnelheid = nieuweSnelheidBerekenen(xCurrentPos, xSnelheid, 1920 /*breedte window*/);
//        //  ySnelheid = nieuweSnelheidBerekenen(yBeginLoc, ySnelheid, height);
//    //    println(visuelePos);
//
//    }
//
//    // berekent de nieuwe locatie
//    int nieuweLocBerekenen(int huidigeLoc, int snelheid) {
//        int nieuweLoc = huidigeLoc + snelheid;
//        return nieuweLoc;
//    }
//
//    // bepaald of de monster naar links of naar rechts gaat
//    int xSnelheidRichtingBepaler() {
//
//        if (xRichtingBepaler == 0) {
//            xSnelheid = int(random(4, 12));
//        }
//        if (xRichtingBepaler == 1) {
//            xSnelheid = int(random(-12, -4));
//        }
//
//        return xSnelheid;
//    }
//
//    int benIkAlLaagGenoeg() {
//        if (yBeginLoc > 1080/*hoogte window*/) {
//            return xBeginLoc;
//        }
//        else {
//            return 0;
//        }
//    }
//
//    // berekent de nieuwe snelheid
//    int nieuweSnelheidBerekenen(int positie, int snelheid, int rand) {
//
//        if (positie >= rand || positie <= 0) {
//            snelheid = snelheid * -1;
//        }
//
//        return snelheid;
//    }
//
//    // tekent peguinMonster
//    void penguinMonsterTekenaar(int xLoc, int yLoc) {
//        //Enemy
//        //torso
//        image(lichaam, xLoc, yLoc, xtorso, ytorso);
//
//    }
};

