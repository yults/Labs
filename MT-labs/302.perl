while($tx = <>) {
    $t.=$tx;
}
$t =~ s/<.*?>//g; 
$t =~ s/\s+//; 
$t =~ s/((\s)*\n){2,}/\n\n/g;
$t =~ s/\s+$/\n/;
$t =~ s/ +/ /mg;
$t =~ s/^ +//mg; 
$t =~ s/ +$//mg;
print($t);

