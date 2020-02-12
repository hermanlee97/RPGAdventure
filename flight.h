int flight(Player player, Enemy enemy)
{
    int playerHP;

    // Since you're running take some damage. (Later loose some coins too.)
    playerHP = player.hp - enemy.damage;

    return playerHP;
}
