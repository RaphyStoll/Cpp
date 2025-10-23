#!/bin/bash

echo "=== Test Account.cpp ==="
echo ""
echo "Compilation..."
make re

if [ $? -ne 0 ]; then
    echo "❌ Erreur de compilation"
    exit 1
fi

echo "✅ Compilation réussie"
echo ""
echo "Exécution du programme..."
echo ""

./account

echo ""
echo "=== Vérification de la sortie ==="
echo ""

# Récupère la sortie sans timestamp
./account | sed 's/\[.*\] //' > output_no_time.log
cat "../subject/CPP Module 00 Log Jan 4 1992.log" | sed 's/\[.*\] //' > expected_no_time.log

if diff output_no_time.log expected_no_time.log > /dev/null; then
    echo "✅ La sortie correspond parfaitement au log attendu (hors timestamp)"
else
    echo "⚠️  Différences détectées (vérification manuelle recommandée):"
    diff output_no_time.log expected_no_time.log
fi

# Nettoyage
rm -f output_no_time.log expected_no_time.log

echo ""
echo "=== Tests terminés ==="
