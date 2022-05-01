#include "Game.hpp"

using namespace coup;

Game::Game()
{
    _Ngame = "Coup";
    _turn = 0;
    active = false;
    _numberOfPlayer = 0;
}
string Game::turn()
{
    return (_numberOfPlayer >= 2) ? *_players[_turn]->getName() : "The game is waiting for more players";
}
vector<string> Game::players()
{
    vector<string> names;
    for (Player *obj : _players)
    {
        if (obj->is_alive())
        {
            names.push_back(*obj->getName());
        }
    }
    return names;
}
vector<Player *> Game::players_obj()
{
    return _players;
}
string Game::winner()
{
    vector<string> names = players();
    if (names.size() == 1)
    {
        return names[0];
    }
    return "The game is not over yet";
}
void Game::incPlayerNumber()
{
    this->_numberOfPlayer++;
}
void Game::addPlayer(Player *p)
{
    if (_numberOfPlayer > MAX_PLAYERS)
    {
        throw invalid_argument("The game is designed for 2-6 players");
    }
    cout << "Hello Player " << *p << endl;
    _players.push_back(p);
    incPlayerNumber();
}
unsigned int Game::getTurn() const
{
    return _turn;
}
void Game::incTurn()
{
    _turn = (_turn + 1) % _numberOfPlayer;
    ;
}
unsigned int Game::get_numberOfPlayer() const
{
    return _numberOfPlayer;
}
