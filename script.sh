make;
echo -e "\033[33m  ___________________ _______  ___________   _____    ___________________________________________"
echo " /  _____/\_   _____/ \      \ \_   _____/  /  _  \   \__    ___/\______   \_   _____/\_   _____/"
echo "/   \  ___ |    __)_  /   |   \ |    __)_  /  /_\  \    |    |    |       _/|    __)_  |    __)_"
echo "\    \_\  \|        \/    |    \|        \/    |    \   |    |    |    |   \|        \ |        \\"
echo " \______  /_______  /\____|__  /_______  /\____|__  /   |____|    |____|_  /_______  //_______  /"
echo "        \/        \/         \/        \/         \/                     \/        \/         \/"
echo -e "\033[32mQuel est le chemin de votre fichier.csv ?\033[0m"
read path
./Genea $path;
make clean