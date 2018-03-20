# Uso: sh uva_downloader.sh numero_problema1 numero_problema2 ...
# Descarga los pdf con los enunciados de los problemas cuyo numero sea el/los pasado(s) por argumento
for var in "$@"
do
	URL="https://uva.onlinejudge.org/external/${var: : -2}/$var.pdf"
	wget $URL
done

