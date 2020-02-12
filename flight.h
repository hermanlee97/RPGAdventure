int flight(Player player, Enemy enemy)
{
    int fHP;

    // Since you're running take some damage. (Later loose some coins too.)
    fHP = player.hp - enemy.damage;

    // Display Message.
    std::cout << "\nThe enemy dealt " << enemy.damage - player.defence << " damage to you!" << std::endl;

    // player.gold = player.gold-(player.gold/100);

    return fHP;
}
