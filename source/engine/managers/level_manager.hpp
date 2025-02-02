#pragma once

#include "../engine_api.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class ENGINE_API LevelManager final
{
public:

	static const int MAX_X = 24;
	static const int MAX_Y = 15;

    struct LevelTile
    {
        sf::Sprite sprite;
        bool walkable = true;
        bool final_state = false;
    };

    struct TilePrototype
    {
        sf::Texture texture;
        bool walkable = true;
        bool final_state = false;
    };

public:

    static LevelManager* get();

    void start_up();

    void shut_down();

    bool is_walkable(int x, int y);
    bool is_final(int x, int y);

    float tile_scaling();

    void load_level(const std::string& filename);

    void render(sf::RenderWindow& win);

private:

    LevelTile _level_tiles[MAX_X][MAX_Y];

    std::map<char, TilePrototype> _tile_prototype;
};
