#pragma once

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "managers/render_manager.hpp"
#include "managers/entity_manager.hpp"
#include "managers/sound_manager.hpp"
#include "managers/level_manager.hpp"
#include "component/sprite_component.hpp"

class Game : public Entity
{
private:

    enum class GameState
    {
        MENU,
        MENU_TO_GAME,
        GAME,
        GAME_TO_GAME_OVER,
        GAME_OVER,
        GAME_OVER_TO_MENU,
        LEVEL_FINISHED_TO_MENU,
        MENU_TO_NEW_LEVEL,
        EXIT
    };

	const static int MAX_LEVEL = 5;

public:

    Game();

    ~Game();

    bool is_finished();

protected:

    void start() override;

    void update(float delta_time) override;

    void handle_events(sf::Event& e) override;

private:

    void menu(float delta_time);

    void menu(sf::Event& e);

    void menu_to_game();

    void game(float delta_time);

    void game(sf::Event& e);

    void game_over(sf::Event& e);

    void game_over(float delta_time);

    void game_to_game_over();

    void level_finished_to_menu();

    void menu_to_new_level(float delta_time);

    void menu_to_new_level(sf::Event& e);

    void exit();

    void deload_level();

    void load_level_01();

    void load_level_02();

    void load_level_03();

    void load_level_04();

    void load_level_05();

    void load_level_06();

    void load_level_07();

    void load_level_08();

    void load_level_09();

    void load_level_10();

private:

    GameState _game_state;

    Player* _player;
    Entity* _left_player;
    Entity* _right_player;
    Entity* _background;
    Entity* _logo;
    std::vector<Enemy*> _enemies;
    sf::Vector2f _final_state;

    bool _is_finished;
    bool _left_selected;
    bool _left_down;
    bool _right_down;
    bool _end_selected;
    float _left_scale;
    float _right_scale;
    int _level_num;
};
