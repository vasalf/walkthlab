echo $(for f in $(for s in $(find src/ -type f); do echo $s; done | egrep -v "[.swo|.swp]$"); do echo -n $(du -b $f | awk '{print $1}') + ; done) 0 | bc
