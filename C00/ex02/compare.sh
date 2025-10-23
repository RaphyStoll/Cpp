#!/bin/bash

echo "=== Comparaison avec le log original ==="
echo ""

# Couleurs
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Exécution du programme
./account > my_output.log 2>&1

# Comparaison ligne par ligne (sans timestamp)
echo "Vérification des valeurs (sans tenir compte du timestamp)..."
echo ""

# Extrait les valeurs importantes
grep -o "index:[0-9]*;amount:[0-9]*;created" my_output.log > my_values.txt
grep -o "index:[0-9]*;amount:[0-9]*;created" "../subject/CPP Module 00 Log Jan 4 1992.log" > original_values.txt

grep -o "accounts:[0-9]*;total:[0-9]*;deposits:[0-9]*;withdrawals:[0-9]*" my_output.log >> my_values.txt
grep -o "accounts:[0-9]*;total:[0-9]*;deposits:[0-9]*;withdrawals:[0-9]*" "../subject/CPP Module 00 Log Jan 4 1992.log" >> original_values.txt

grep -o "index:[0-9]*;p_amount:[0-9]*;deposit:[0-9]*;amount:[0-9]*;nb_deposits:[0-9]*" my_output.log >> my_values.txt
grep -o "index:[0-9]*;p_amount:[0-9]*;deposit:[0-9]*;amount:[0-9]*;nb_deposits:[0-9]*" "../subject/CPP Module 00 Log Jan 4 1992.log" >> original_values.txt

grep -o "withdrawal:refused" my_output.log >> my_values.txt
grep -o "withdrawal:refused" "../subject/CPP Module 00 Log Jan 4 1992.log" >> original_values.txt

if diff my_values.txt original_values.txt > /dev/null; then
    echo -e "${GREEN}✅ Toutes les valeurs correspondent parfaitement au log original !${NC}"
else
    echo -e "${YELLOW}⚠️  Quelques différences détectées :${NC}"
    diff my_values.txt original_values.txt
fi

# Nettoyage
rm -f my_output.log my_values.txt original_values.txt

echo ""
echo "Note: L'ordre des destructeurs peut varier selon le compilateur."
echo "Cela est normal et mentionné dans le sujet."
