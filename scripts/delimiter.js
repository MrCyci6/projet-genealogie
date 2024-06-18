/*
Destiné à raccourcir un arbre avec un délimiteur en enlevant tous les id au dessus de celui ci
 */

const fs = require('fs');

fs.readFileSync("list.csv", "utf8").split("\n").forEach(line => {
	let splitted = line.split(",");
	let delimiter = 1000;
	fs.appendFileSync(`${delimiter}.txt`, `${splitted[0]},${splitted[1] > delimiter ? 0 : splitted[1]},${splitted[2] > delimiter ? 0 : splitted[2] },${splitted[3]},${splitted[4]},${splitted[5]},${splitted[6]}`);
});