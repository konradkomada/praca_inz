for ip in $(iptables -n -L | grep DROP | awk {print } | grep -v DROP | grep -v 0.0.0.0); do whois ${ip}; done
