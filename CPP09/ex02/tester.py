import subprocess
import random
import sys
import os

def print_help():
    help_text = """
Usage: python3 tester.py <fichier.cpp> <taille> [options]

Arguments obligatoires:
  fichier.cpp       Le fichier source C++ à compiler et tester.
  taille            Le nombre d'éléments (entiers) à générer pour le tri.

Options:
  --infinite        Exécute les tests en boucle jusqu'à une erreur ou Ctrl+C.
  --doublon=on      Autorise les doublons dans les données (par défaut).
  --doublon=off     Génère uniquement des nombres uniques.
  -h, --help        Affiche ce message d'aide.

Exemples:
  python3 tester.py main.cpp 15
  python3 tester.py main.cpp 100 --infinite --doublon=off
    """
    print(help_text)

def run_test(executable, size, allow_duplicates):
    # 1. Génération des données
    if allow_duplicates:
        test_data = [random.randint(0, 1000000000000) for _ in range(size)]
    else:
        # random.sample garantit l'absence de doublons
        test_data = random.sample(range(0, 1000000000000), size)
    
    str_data = [str(x) for x in test_data]
    
    # 2. Appel de l'exécutable avec les données en ARGV
    try:
        process = subprocess.Popen(['./' + executable] + str_data, 
                                   stdout=subprocess.PIPE, 
                                   stderr=subprocess.PIPE,
                                   text=True)
        stdout, stderr = process.communicate()
        
        if stderr:
            print("\n❌ Erreur d'exécution (stderr) :")
            print(stderr)
            return False

        output_parts = stdout.strip().split()
        if not output_parts:
            print("\n❌ Erreur : L'exécutable n'a rien renvoyé.")
            return False
            
        result = list(map(int, output_parts))
        expected = sorted(test_data)
        
        if result == expected:
            return True
        else:
            print(f"\n❌ ÉCHEC DU TEST !")
            print(f"Entrée : {test_data}")
            print(f"Attendu : {expected}")
            print(f"Obtenu  : {result}")
            return False
            
    except Exception as e:
        print(f"\nErreur système : {e}")
        return False

def main():
    # Affichage du help si aucun argument ou si -h/--help
    if len(sys.argv) < 2 or "--help" in sys.argv or "-h" in sys.argv:
        print_help()
        sys.exit(0)

    if len(sys.argv) < 3:
        print("Erreur: Argument 'taille' manquant.")
        print_help()
        sys.exit(1)

    cpp_file = sys.argv[1]
    
    try:
        size = int(sys.argv[2])
    except ValueError:
        print(f"Erreur: '{sys.argv[2]}' n'est pas un nombre valide pour la taille.")
        sys.exit(1)
    
    # Parsing des options
    infinite_mode = "--infinite" in sys.argv
    allow_duplicates = True 
    for arg in sys.argv:
        if arg == "--doublon=off":
            allow_duplicates = False
        elif arg == "--doublon=on":
            allow_duplicates = True

    executable = "PmergeMe"


    print(f"🚀 Tests (Taille: {size}, Infini: {infinite_mode}, Doublons: {allow_duplicates})")
    
    count = 1
    try:
        while True:
            if run_test(executable, size, allow_duplicates):
                sys.stdout.write(f"\r✅ Test #{count} réussi")
                sys.stdout.flush()
                count += 1
                if not infinite_mode:
                    print("\nFin du test unique.")
                    break
            else:
                # Arrêt immédiat en cas d'erreur pour voir le log
                sys.exit(1)
    except KeyboardInterrupt:
        print(f"\n\n🛑 Tests interrompus ({count-1} tests effectués).")
    finally:
        # Nettoyage de l'exécutable
        if os.path.exists(executable):
            os.remove(executable)

if __name__ == "__main__":
    main()