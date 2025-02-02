#include "sound_manager.hpp"
#include "../component/sound_component.hpp"
#include "../component/component.hpp"
#include "../entity.hpp"

SoundManager* SoundManager::get()
{
    static SoundManager instance;
    return &instance;
}

SoundComponent *SoundManager::load_sound_component(Entity *_entity, const std::string &_sound_file, const std::string &_sound_type)
{
    SoundComponent *_sound_component = new SoundComponent();
    _sound_component->set_sound(_sound_file);
    _sound_component->add_entity(_entity);
    _entity->add_component(_sound_component);

    _sound_components[_sound_type] = _sound_component;
    return _sound_component;
}

void SoundManager::start_up()
{
    // TODO
}

void SoundManager::play_sound(const std::string& _sound_type, bool repeat)
{
    _sound_components[_sound_type]->_music.play();
    _sound_components[_sound_type]->_music.setLoop(repeat);
}

void SoundManager::stop_sound(const std::string& sound_type)
{
    _sound_components[sound_type]->_music.stop();
}

void SoundManager::shut_down()
{
    for (auto sound_component : _sound_components_vec)
    {
        sound_component->_music.stop();
        delete sound_component;
    }
    _sound_components.clear();
    _sound_components_vec.clear();
}

void SoundManager::deregister_sound_component(SoundComponent * sound)
{
    for (int i = 0; i < _sound_components_vec.size(); ++i)
    {
        if (_sound_components_vec[i] == sound)
        {
            _sound_components_vec.erase(_sound_components_vec.begin() + i);
            return;
        }
    }

    // Iterator pointing to first element of unordered_map
    std::unordered_map<std::string, SoundComponent*>::iterator it = _sound_components.begin();

    // Search for an element with value 2
    while (it != _sound_components.end())
    {
        if (it->second == sound)
        {
            _sound_components.erase(it);
            break;
        }

        ++it;
    }
}
