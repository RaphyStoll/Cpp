from pathlib import Path
import os
import subprocess
from enum import Enum

class BinName(Enum):
    MEGAPHONE = "megaphone"
    PHONEBOOK = "phonebook"
    ACCOUNT = "account"


class CppTester:
    def __init__(self, exercise_path):
        self.path = Path(exercise_path)

    def binary_exists(self):
        """Vérifie si le binaire existe et est exécutable"""
        if not self.path.exists():
            return False
        if not self.path.is_file():
            return False
        if not os.access(self.path, os.X_OK):
            return False
        return True
    
    def run_test(self, exercise_name):
        """
        Lance le test pour l'exercice donné
        Ignore si le binaire n'existe pas
        """
        # Dictionnaire des tests disponibles
        tests = {
            BinName.MEGAPHONE.value: self._test_megaphone,
            BinName.PHONEBOOK.value: self._test_phonebook,
            BinName.ACCOUNT.value: self._test_account,
        }

        # Si le binaire n'existe pas, on ignore (skip)
        if not self.binary_exists():
            print(f"⏭️  Skipping {exercise_name}: binary not found")
            return None  # None = skipped, pas d'erreur
        
        # Si le test existe, on l'exécute
        if exercise_name in tests:
            print(f"🧪 Running test: {exercise_name}")
            return tests[exercise_name]()
        else:
            print(f"⚠️  No test defined for: {exercise_name}")
            return None
    
    def _run_binary(self, args=None, stdin=None, timeout=5):
        """Helper pour exécuter le binaire"""
        if not self.binary_exists():
            raise FileNotFoundError(f"Binary not found: {self.path}")
        
        command = [str(self.path)]
        if args:
            command.extend(args)
        
        try:
            return subprocess.run(
                command,
                capture_output=True,
                text=True,
                input=stdin,
                timeout=timeout
            )
        except subprocess.TimeoutExpired:
            print(f"⏱️ Timeout: {self.path}")
            raise
    
    # Tests privés
    def _test_megaphone(self):
        """Test pour megaphone"""
        result = self._run_binary(args=["hello", "world"])
        if "HELLO WORLD" in result.stdout:
            print("✅ megaphone passed")
            return True
        else:
            print("❌ megaphone failed")
            return False