#include "managers/entity_manager.hpp"
#include "managers/render_manager.hpp"
#include "managers/sound_manager.hpp"
#include "managers/level_manager.hpp"
#include "player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main(int argc, char* argv)
{
    sf::RenderWindow win(sf::VideoMode(32 * 32, 32 * 32), "Undies");

    SoundManager* sound_manager = SoundManager::get();
    EntityManager* entity_manager = EntityManager::get();
    RenderManager* render_manager = RenderManager::get(); // = RenderManager::get();
    LevelManager* level_manager = LevelManager::get();

    render_manager->start_up(&win);
    level_manager->start_up();
    level_manager->load_level("data/level_01.txt");

    Entity* player = new Player();
    entity_manager->register_entity(player);
    SoundComponent* sound_component = sound_manager->load_sound_component(player, "data/Undies_main_theme_-_16-bit.wav", "mainsound");
    sound_manager->play_sound("mainsound");

    sf::Clock clock;
    float delta_time = 0.0f;

    while (true)
    {
        entity_manager->handle_events(win);
        entity_manager->update(delta_time);

        win.clear();

        level_manager->render(win);

        // Render all objects.
        render_manager->render();

        win.display();

        sf::Time time = clock.getElapsedTime();
        clock.restart();
        delta_time = time.asSeconds();
    }

    level_manager->shut_down();
    render_manager->shut_down();
    sound_manager->shut_down();

    return 0;
}
