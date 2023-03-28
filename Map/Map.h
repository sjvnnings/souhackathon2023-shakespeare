//
// Created by Brayden Edwards on 3/28/23.
//

#ifndef SOUHACKATHON2023_SHAKESPEARE_MAP_H
#define SOUHACKATHON2023_SHAKESPEARE_MAP_H


namespace Game {
    namespace Map{
        class Map {
            private:
                int x;
                int y;

            public:
                Map(int x, int y);
                int GetX();
                int GetY();
                void GenerateMap(int x, int y);
            };
    }
}




#endif //SOUHACKATHON2023_SHAKESPEARE_MAP_H
