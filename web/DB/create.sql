create database project_nameless;

use project_nameless;

create table if not exists users(
	user_id bigint unsigned not null primary key auto_increment,
	user_email varchar(155) null,
	user_create_date datetime default now()
)ENGINE=InnoDB  DEFAULT CHARSET=utf8;

create table if not exists user_ranking(
	ranking_id bigint unsigned not null primary key auto_increment,
	user_id bigint unsigned not null,
	user_ranking smallint(10) not null default 0,
	user_ranking_date datetime default now()
)ENGINE=InnoDB  DEFAULT CHARSET=utf8;

create table if not exists user_ranking_app(
	ranking_id bigint unsigned not null,  
	ranking_app_id bigint unsigned not null,
	ranking_app_domain bigint unsigned not null,
	CONSTRAINT pk_app_ranking_domain PRIMARY KEY (ranking_app_id, ranking_id, ranking_app_domain)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

create table if not exists user_meta(
	meta_id bigint unsigned not null primary key auto_increment,
	user_id bigint unsigned not null,
	meta_key varchar(250) not null default '',
	meta_value text not null default ''
)ENGINE=InnoDB  DEFAULT CHARSET=utf8;

create table if not exists app (
	app_id bigint unsigned not null primary key auto_increment,
	email_owner varchar(150) not null,
	name_owner varchar (50) not null,
	website_owner varchar (150) not null,
	app_hash varchar (255) not null,
	app_create_date datetime default now()
)ENGINE=InnoDB  DEFAULT CHARSET=utf8;

create table if not exists app_domain (
	app_id bigint unsigned not null, 
	domain_name varchar (150) not null,
	app_domain_add_date datetime default now(),
	CONSTRAINT pk_app_domain PRIMARY KEY (app_id, domain_name)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

ALTER TABLE app_domain ADD FOREIGN KEY (app_id) REFERENCES app (app_id) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE user_ranking ADD FOREIGN KEY (user_id) REFERENCES users (user_id) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE user_meta ADD FOREIGN KEY (user_id) REFERENCES users (user_id) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE user_ranking_app ADD FOREIGN KEY (ranking_id) REFERENCES user_ranking (ranking_id) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE user_ranking_app ADD FOREIGN KEY (ranking_app_id) REFERENCES app (app_id) ON DELETE CASCADE ON UPDATE CASCADE;
ALTER TABLE user_ranking_app ADD FOREIGN KEY (ranking_app_domain) REFERENCES app_domain (pk_app_domain) ON DELETE CASCADE ON UPDATE CASCADE;
