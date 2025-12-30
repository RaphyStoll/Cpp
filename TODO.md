Les mini-helpers qui vont vraiment te faciliter webserv (ordre de valeur)

1) Buffer : accumulation + extraction CRLF (indispensable)

But : gérer la lecture incrémentale de HTTP sans te battre.
	•	append(data, n)
	•	find("\r\n\r\n")
	•	readLineCRLF()
	•	consume(n)

Sans ça, ton parsing devient vite du spaghetti.

2) String parsing utils : split/trim/case-insensitive (simple mais partout)
	•	trim(), ltrim/rtrim
	•	split(str, delim) (avec option “limit”)
	•	iequals(a,b) (case-insensitive)
	•	parse_uint(), parse_size_t() avec validation stricte

3) HTTP mini-primitives : parse start-line + headers proprement
	•	parse_request_line("GET /path HTTP/1.1")
	•	parse_header_line("Host: example.com")
	•	normalisation des headers (lowercase key)
	•	has_header, get_header, content_length

Même si tu ne fais pas un “gros module HTTP”, ces 20 fonctions te sauvent.

4) Net wrappers : petites fonctions POSIX pour éviter de répéter 200 fois
	•	set_non_blocking(fd)
	•	set_reuseaddr(fd)
	•	set_nodelay(fd) (optionnel)
	•	sockaddr_to_string()
	•	petite classe RAII Fd (close automatique)

5) Logger : logs lisibles avec contexte
	•	niveaux DEBUG/INFO/WARN/ERROR
	•	prefix automatique : [conn=12 fd=34 10.0.0.5:53211]

Quand tu debug du keep-alive, c’est la différence entre 10 min et 3h.

6) Timeout / Clock
	•	now_ms()
	•	deadline par connexion
	•	elapsed_since(last_activity)

Webserv sans timeouts = serveur “qui reste bloqué” dès que tu testes un cas tordu.

7) Config parsing helpers (quand tu attaqueras la conf)
	•	lecture fichier + strip comments
	•	tokenizer simple
	•	parse d’IP/port, chemins, bool, tailles (k/m/g)
	•	erreurs avec line/column